#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <set>
#include <queue>
#include <map>
#include <stack>
using namespace std;

#define mod 1000000007
#define ten5 100005
#define ten52 200005
#define ten6 1000005
#define PI 3.1415926
#define pb(x) push_back(x)
#define mkpr(x,y) make_pair(x,y)
#define all(x) x.begin(),x.end()

/*#define Conn(x,y) x##y
#define ToChar(x) #@x
#define ToStr(x) #x*/


typedef long long int ll;

//ll num[ten5];
//ll num2[ten5];
//char cmap[10][10];
//priority_queue<ll> pqll;   //decrease
//priority_queue<double> pqd;
//stack<int> stk;
//vector<pair<ll,ll>> vpll;
//vector<pair<double,double>> vpdd;
//vector<ll> vll[ten52];
//vector<double> vd;
//deque<ll> deq[55];
//list<int> li;
//set<int> sint;
//set<ll> sll;
//set<char> sch;
//set<string> sStr;
//map<ll,ll> mp;

/*ll cmp(pair<ll,ll> a,pair<ll,ll> b)
{
    return a.first<b.first;
    //arrising
}*/

vector<ll> num(26),num2(26);

int main()
{
    long long int m,n,o,i,j,k=1;
    string s,s1;
    cin>>s;
    cin>>s1;
    for(i=0;i<s.size();i++)
    {
        num[s[i]-'a']++;
        num2[s1[i]-'a']++;
    }
    sort(all(num));
    sort(all(num2));
    cout<<(num==num2?"Yes":"No");
    return 0;
}



