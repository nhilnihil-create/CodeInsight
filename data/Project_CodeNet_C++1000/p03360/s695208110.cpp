#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
using P = pair <int, int>;



int main(){
     int a,b,c;
     cin >> a >>b >>c;
     int k;
     cin >> k;
     vector<int> s(3);
     s[0] =a , s[1] =b, s[2]=c;
     sort(s.begin(),s.end());
     rep(i,k){
         s[2]=s[2]*2;
     }
     int count =0;
     rep(i,3) count += s[i];
     cout << count << endl;
}