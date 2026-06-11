#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i,s,n) for(int i = (s); i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(){
   int n;
   cin >> n;
   vector<P> v;
   v.push_back(make_pair(0, 0));
   rep(i, n) { 
       int t, x, y;
       cin >> t >> x >> y;
       v.push_back(make_pair(t, x + y));
   }
   bool flag = true;
   rep(i, n) {
       int time = v[i + 1].first - v[i].first;
       int dist = abs(v[i + 1].second - v[i].second);
       if(time == dist)
           continue;
       else if(time > dist) {
           if(dist == 0) {
               time = time - 4;
           } else {
               time = time - dist;
           }
           if(time % 2 != 0) {
               flag = false;
               break;
           }
       }else{
           flag = false;
           break;
       }
   }
   if(flag)
       cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}