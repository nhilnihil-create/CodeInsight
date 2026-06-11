#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
 
using namespace std;
 
#define PB push_back
#define MP make_pair
#define REP(i,n) for(int i=0;i<(n);i++)

int main()
{
    string s;
    cin>>s;
    int cnt=0;
    REP(i,s.size())if(s[i]=='x')cnt++;
    if(cnt>=8)cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}
