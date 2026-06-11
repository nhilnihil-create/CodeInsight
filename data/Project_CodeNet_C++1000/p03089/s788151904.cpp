#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    rep(i,n){
        cin>>a[i];
        a[i]--;
    }

    vector<int> res;
    rep(i,n){
        int pivot=-1;
        for(int j=(int)a.size()-1;j>=0;j--){
            if(a[j]==j){
                pivot=j;
                break;
            }
        }
        if(pivot==-1){
            cout<<-1<<endl;
            return 0;
        }

        res.push_back(pivot+1);
        a.erase(a.begin()+pivot);
    }

    reverse(all(res));
    rep(i,n) cout<<res[i]<<endl;


}
