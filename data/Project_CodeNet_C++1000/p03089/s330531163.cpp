#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
using P = pair<ll,ll>;
using ld=long double;

int main(){
  int n;cin >>n;
  vector<int>b(n);
    for (int i = 0; i < n; ++i) {
        cin >>b[i];
    }
  vector<int>nx;
  vector<int>ans;
    while(1) {
        bool flg=true;
        for (int i = n - 1; i >=0; --i) {
            if(b[i]==i+1&&flg){
                ans.push_back(i+1);
                flg=false;
            }
            else {
                nx.push_back(b[i]);
            }
        }
        reverse(all(nx));
//        for(auto e:nx){
//            cout <<e<<" ";
//        }
//        cout <<endl;
        if(nx.empty())break;
        if(nx.size()==n){
            cout <<-1<<endl;
            return 0;
        }
        b=nx;
        nx.clear();
        n=b.size();
    }
    reverse(all(ans));
    for (int i = 0; i < ans.size(); ++i) {
        cout <<ans[i]<<endl;
    }
}
