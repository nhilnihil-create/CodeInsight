/*g++ main.cpp -o main.out*/
/*./main.out*/

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;

#define LL long long
#define ll long long
#define LD long double
#define Mod 1000000007
#define L_Mod 17100000013

const double eps = 1e-9;
const int INF = 0x3f3f3f3f;
const double PI = 3.1415926535;

#define NO_TLE std::ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

#define ree(a,n) memset(a,n,sizeof(a));

#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define red(i,l,u) for(int (i)=(int)(l);(i)>=(int)(u);--(i))

int m[105][105];

int main()
{
    int a,b;
    cin>>a>>b;
    rer(i,51,100)rer(j,1,100)m[i][j]=1;
    a--,b--;

    for(int i=1; i<=50&&a>0; i+=2)
    {
        for(int j=1; j<=100; j+=2)
        {
            m[i][j]=1;
            a--;
            if(a<=0)
                break;
        }
        if(a<=0)
            break;
    }
    for(int i=52; i<=100&&b>0; i+=2)
    {
        for(int j=1; j<=100; j+=2)
        {
            m[i][j]=0;
            b--;
            if(b<=0)
                break;
        }
        if(b<=0)
            break;
    }
    cout<<100<<' '<<100<<endl;
    rer(i,1,100)
    {
        rer(j,1,100)
        {
            if(m[i][j]==1)cout<<'.';
            else cout<<'#';
        }
        cout<<endl;
    }
    return 0;
}











//







