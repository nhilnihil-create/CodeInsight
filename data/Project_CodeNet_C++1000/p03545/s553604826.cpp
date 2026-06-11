#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <iostream>
#include <fstream>
#include <numeric>
#include <cstring>
#include <cassert>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <cmath>
#include <set>
#include <map>
#include <functional>
#include <bitset>
#include <iomanip>
#include <stack>
#include <list>
using namespace std;
#define ll           long long
#define all(v)       (v).begin() , (v).end()
#define vi           vector <ll>
#define vii          vector <pair<ll,ll>>
#define ii           pair<ll,ll>
#define sz(v)	     ((int)((v).size()))
#define lp(i,a,b)    for(int i=a;i<b;i++)
#define pb           push_back
#define pf           push_front
#define F            first
#define S            second
#define endl         "\n"
#define IOS          ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const double PI = 3.14159265358979323846;
const ll inf=2e9,MOD=1e9+7,MAX=1e5+2;


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    IOS;
    string s;
    cin>>s;
    int a[]={1,-1};
    lp(i,0,2)
        lp(j,0,2)
            lp(k,0,2)
                if(s[0]-'0'+(s[1]-'0')*a[i]+(s[2]-'0')*a[j]+(s[3]-'0')*a[k]==7)
                    return cout<<s[0]<<(a[i]==1?"+":"-")<<s[1]<<(a[j]==1?"+":"-")<<s[2]<<(a[k]==1?"+":"-")<<s[3]<<"=7",0;
}
