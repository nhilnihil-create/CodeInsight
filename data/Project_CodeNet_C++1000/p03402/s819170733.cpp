#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define ff first
#define ss second
#define sz(x) (int)x.size()
#define all(x) (x).begin(),(x).end()
#define F(i,x,n,y) for(i=x;i<n;i+=y)
#define fi(i,x,n) for(i=x;i<n;++i)
#define f(n) for(int i=0;i<n;++i)
#define fr(i,x,n) for(i=x;i>=n;--i)
#define endl '\n'

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

int ans[105][105];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a,b;
    cin>>a>>b;
    int i,j;
    fi(i,1,101){
        fi(j,1,51){
            ans[i][j]=1;
        }
    }
    int cnt=0;
    F(i,1,101,2){
        int start=1;
        if(i%2==0){
            start=2;
        }
        F(j,start,51,2){
            if(cnt==a-1) break;
            ans[i][j]=0;
            ++cnt;
        }
        if(cnt==a-1) break;

    }
    cnt=0;
    F(i,1,101,2){
        int start=52;
        if(i%2==0){
            start=53;
        }
        F(j,start,101,2){
            if(cnt==b-1) break;
            ans[i][j]=1;
            ++cnt;
        }
        if(cnt==b-1) break;
    }
    cout<<"100 100"<<endl; 
    fi(i,1,101){
        fi(j,1,101){
            if(ans[i][j]==0) cout<<".";
            else cout<<"#";
        }
        cout<<endl;
    }


    return 0;
}
