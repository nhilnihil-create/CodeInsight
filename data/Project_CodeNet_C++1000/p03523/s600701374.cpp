#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include <numeric>
#include<map>
#include<unordered_map>
#include <queue>
 
using namespace std;
using ll=long long;
#define rep(i,n)  for(ll i=0;i<n;++i)
#define all_map(itr,mp) for(auto itr=mp.begin();itr!=mp.end();itr++)
#define ALL(a) (a).begin(),(a).end()

int main(){
    string s;
    cin >> s;
    
    string ans = "";
    if(s.front()=='A')s.erase(s.begin());
    if(s.back()=='A')s.pop_back();
    if(s=="KIHBR"||s=="KIHBAR"||s=="KIHABR"||s=="KIHABAR")cout << "YES";
    else cout << "NO";
}