#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <ctime>
#include <cassert>
#include <iomanip>
#include <vector>
#include <cstdio>
#include <float.h>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <stack>
#include <functional>
 
using namespace std;
 
#define endl '\n'
#define MOD 1000000007
#define INF 1ll<<30
#define MAX 100010
#define eps 1e-11
#define bit_max 1ll<<32
#define _USE_MATH_DEFINES

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    
    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    string c,d;
    c ="";
    d ="";
    for(int i=0;i<q;i++)
    {
        char cc,dd;
        cin>>cc>>dd;
        c+=cc;
        d+=dd;
    }
    int l=-1,r=n;
    int mid = l+((r-l)/2);
    int l_max=-1;
    for(int i=0;i<80;i++)
    {
        if(l+1<r)
        {
            mid = l+((r-l)/2);
            int index = mid;
            char val = s[index];
            bool reached = false;
            for(int j=0;j<q;j++)
            {
                if(c[j]==val&&d[j]=='L')
                {
                    index--;
                }
                else if(c[j]==val&&d[j]=='R')
                {
                    index++;
                }
                if(index ==-1)
                {
                    reached=true;
                    break;
                }
                else if (index ==n)
                    break;
                val = s[index];      
            }
            if(reached)
            {
                l = mid;
                l_max = mid;
            }
            else
                r = mid;
        }
        else
        {
            break;
        }
    }

    l=-1,r=n;
    mid = l+((r-l)/2);
    int r_max=n;
    for(int i=0;i<80;i++)
    {
        if(l+1<r)
        {
            mid = l+((r-l)/2);
            int index= mid;
            char val = s[index];
            bool reached = false;
            for(int j=0;j<q;j++)
            {
                if(c[j]==val&&d[j]=='L')
                {
                    index--;

                }
                else if(c[j]==val&&d[j]=='R')
                {
                    index++;
                }
                if(index == n)
                {
                    reached=true;
                    break;
                }      
                else if (index ==-1)
                    break;
                val = s[index];      
            }
            if(reached)
            {
                r = mid;
                r_max = mid;
            }
            else
                l = mid;
        }
        else
        {
            break;
        }
    }
    l_max++;
    r_max--;

    cout<<max(0,r_max-l_max+1);
    return 0;
}