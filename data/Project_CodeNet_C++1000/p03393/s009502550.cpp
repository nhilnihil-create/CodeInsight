/*------------------------------------
........Bismillahir Rahmanir Rahim....
..........created by Abdul Aziz.......
------------------------------------*/
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <unordered_map>
#include <queue>
#define   mod  998244353
#define   int  long long 
#define   ld   long double
#define   pb   push_back
#define   vi  vector<int> 
#define   dbg(x)  cerr << #x << " = " << x << '\n'
#define   sz(x)  (int)x.size()
#define   all(a) (a.begin(),a.end())
#define   ff   first
#define   ss   second
#define   pii  pair<int,int> 
#define   lcm(a,b) (a*b)/__gcd(a,b) 
using namespace std;

inline void solve(){
	map <char,bool> cnt;
    string s;cin>>s;
    int n=sz(s);
    for (int i=0;i<n;i++) cnt[s[i]]=true;
    if (n<26){
    	cout << s;
    	for (char c='a';c<='z';c++){
    		if (!cnt[c]){
    			cout << c << endl;
    			return;
    		}
    	}
    }
    else {
    	for (int i=25;i>=0;i--){
    		for (char c=s[i];c<='z';c++){
    			if (cnt[c]==false){
    				for (int j=0;j<i;j++)
    					cout << s[j] ; 
    				cout << c<< endl;
    				return;
    			}
    		}
    		cnt[s[i]]=false;
    	}
    }
    cout << -1 << endl;
}

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}

