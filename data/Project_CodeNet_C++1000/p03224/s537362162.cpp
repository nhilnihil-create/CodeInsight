#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int n,index;
    cin>>n;
    int k=int(sqrt(2*n));
    if(k*(k+1)==2*n){
        k++;
        cout << "Yes\n"<<k<<endl;
        vector<vector<int> > ans(k);
        for(int i=0;i<k;i++){
            index=0;
            for(int j=(i*(i-1)/2)+1;j<=i*(i+1)/2;j++,index++){
                ans[index].pb(j);
            }
            for(int j=(i*(i-1)/2)+1;j<=i*(i+1)/2;j++,index++){
                ans[i].pb(j);
            }
        }
        for(int i=0;i<k;i++){
            cout<< k-1<<" ";
            for(int j=0;j<k-1;j++){
                cout <<ans[i][j]<<" ";
            }
            cout << endl;
        }
    }
    else{
        cout << "No"<<endl;
    }
    return 0;
}