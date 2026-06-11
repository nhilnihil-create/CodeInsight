#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
typedef int64_t llong;
char moji[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
char moji2[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
char moji3[10]={'0','1','2','3','4','5','6','7','8','9'};
#define Sort(a) sort(a.begin(),a.end());
#define Reverse(a) reverse(a.begin(),a.end());
#define ld PRId64
#define n_max 100


float kyori(float sta,int jikan,int ma,int end,float next[]){
    if(sta + jikan <=end){
        next[0]=sta + jikan;
        return (2 * sta + jikan) * jikan /float(2);
    }
    next[0]=end;
    if(ma - sta + ma - end <= jikan) return ma * jikan - (ma - sta) * (ma -sta) /float(2) - (ma - end) * (ma - end )/float(2);
    float tim;
    tim=(end - sta + jikan )/float(2);
    return tim / float(2) * (sta + sta + tim) + (sta + tim + end) *(jikan - tim) / float(2); 
}

int main(){
    int n;
    cin >> n;
    int t[n_max+5];
    int v[n_max+5];
    REP(i,n) cin >> t[i];
    REP(i,n) cin >> v[i];
    int A[n_max+5];
    A[n-1]=0;
    REPR(i,n-2){
        A[i] = min( v[i+1] , A[i+1] + t[i+1]);
        A[i]=min(A[i] , v[i]);
    }
    float ans=0.0;
    int end;
    end=A[0];
    float sta=0;
    float next[1];
    REP(i,n){
        ans+=kyori(sta,t[i],v[i],A[i],next);
        sta=next[0];
    }
    cout << fixed << setprecision(8) << float(ans) << endl;
}

