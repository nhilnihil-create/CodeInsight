#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(llong i = 0;i < n;i++)
#define REPR(i, n) for(llong i = n;i >= 0;i--)
#define FOR(i, m, n) for(llong i = m;i < n;i++)
#define itrfor(itr,A) for(auto itr = A.begin(); itr !=A.end();itr++)
typedef long long llong;
char moji[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
char moji2[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
char moji3[10]={'0','1','2','3','4','5','6','7','8','9'};
#define Sort(a) sort(a.begin(),a.end());
#define Reverse(a) reverse(a.begin(),a.end());
#define prllong(a) cout << a << endl;
#define MAX int(1e5+5)



struct kukan{
    int id;
    int left;
    int right;
};


bool comp_l(kukan a, kukan b){
    return a.left > b.left;
}

bool comp_r(kukan a,kukan b){
    return a.right < b.right;
}

int main(){
    int n;
    cin >> n;
    kukan L[MAX],R[MAX];
    int l,r;
    REP(i,n){
        scanf("%d%d",&l,&r);
        L[i].id=i;
        L[i].left=l;
        L[i].right=r;
        R[i].id=i;
        R[i].left=l;
        R[i].right=r;
    }

    sort(L,L+n,comp_l);
    sort(R,R+n,comp_r);


    llong ans=0,ans2=0;
    bool visited[MAX];
    REP(i,MAX) visited[i] = false;
    bool flag = true;
    int l_ind=0,r_ind=0,tmp=0;
    REP(i,n){
        if(flag){
            while(  visited[ L[l_ind].id ] ){
                l_ind +=1;
            }
            if( tmp < L[l_ind].left){
                ans += L[l_ind].left - tmp;
                tmp = L[l_ind].left;
            }
            else if( L[l_ind].right < tmp){
                ans += tmp - L[l_ind].right;
                tmp = L[l_ind].right;
            }
            visited[ L[l_ind].id ] =true;
            flag = false;
        }
        else{
            while( visited[R[r_ind].id] ) r_ind +=1;
            if( tmp < R[r_ind].left){
                ans += R[r_ind].left - tmp;
                tmp = R[r_ind].left;
            }
            else if( R[r_ind].right < tmp){
                ans += tmp - R[r_ind].right;
                tmp = R[r_ind].right;
            }
            visited[ R[r_ind].id ] = true;
            flag = true;
        }
    }
    ans += abs(tmp);
    ans2= ans;
    ans = 0;

    REP(i,MAX) visited[i] = false;
    flag = false;
    l_ind=0,r_ind=0,tmp=0;
    REP(i,n){
        if(flag){
            while(  visited[ L[l_ind].id ] ){
                l_ind +=1;
            }
            if( tmp < L[l_ind].left){
                ans += L[l_ind].left - tmp;
                tmp = L[l_ind].left;
            }
            else if( L[l_ind].right < tmp){
                ans += tmp - L[l_ind].right;
                tmp = L[l_ind].right;
            }
            visited[ L[l_ind].id ] =true;
            flag = false;
        }
        else{
            while(  visited[R[r_ind].id] ) r_ind +=1;
            if( tmp < R[r_ind].left){
                ans += R[r_ind].left - tmp;
                tmp = R[r_ind].left;
            }
            else if( R[r_ind].right < tmp){
                ans += tmp - R[r_ind].right;
                tmp = R[r_ind].right;
            }
            visited[ R[r_ind].id ] = true;
            flag = true;
        }

    }
    ans += abs(tmp);


    cout << max(ans , ans2) << endl;

}