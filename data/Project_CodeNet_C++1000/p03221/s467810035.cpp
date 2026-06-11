#include<bits/stdc++.h>
#define R(a) freopen(a, "r", stdin);
#define W(a) freopen(a, "w", stdout);
using namespace std;
#define ll long long
#define MX 1e9

string re(int num){
    string ans ;
    while(num){
        ans += (char)(num % 10 + '0');
        num/= 10;
    }
    int sz= ans.size();
    for(int i=1;i<=6-sz;i++)ans+='0';
    reverse(ans.begin(), ans.end());
    return ans;
}
int main(){
   int n, m;
   cin>>n>>m;
   pair<int,pair<int, int> >ar[m+2];
   for(int i = 1;i<= m; i++){
        cin>>ar[i].second.first>>ar[i].first;
        ar[i].second.second = i;
   }

   sort(ar + 1, ar + m+ 1);

   vector<int>v[n + 2];

   for(int i = 1;i<= m;i++){
    v[ar[i].second.first].push_back(ar[i].second.second);
   }
   string res[m+2];

   for(int i = 1;i<=n;i++){
        for(int j = 0;j<v[i].size();j++){
            int x = j + 1;
            res[v[i][j]] = re(i) + re(x);
        }
   }

  for(int i=1;i<=m;i++)cout<<res[i]<<endl;
 return 0;
}
