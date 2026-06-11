#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
 
using namespace std;
 
#define PB push_back
#define MP make_pairA
#define REP(i,n) for(int i=0;i<(n);i++)
int main()
{
    string s;
    cin>>s;
    if(s.size()==2)cout<<s<<endl;
    else{
        REP(i,s.size())cout<<s[s.size()-1-i];
        cout<<endl;
    }
}