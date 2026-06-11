#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <complex>
#include <iomanip>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <cstring>
#include <set>

#define ll long long
#define ld long double
#define HS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define INF 0x3f3f3f3f3f3f3f3f
#define point complex <double>
#define all(a) a.begin(), a.end()
#define pi acos(-1)
#define mod 1000000007


using namespace std;

int main() {

    HS;
    int n;
    cin>>n;
    int arr[205];
    bool odd=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        if(arr[i]%2)
            odd=1;
    }
    if(odd)
        cout << 0 << endl;
    else
    {
        int max=1e6;
        ll ans=1;
        bool notOdd=1;

        while(max--)
        {
            for(int i=0;i<n;i++)
            {
                arr[i]/=2;
                if(arr[i]%2)
                {
                    notOdd=0;
                    break;
                }
            }
            ans+=notOdd;
            if(!notOdd)
                break;


        }
        if(notOdd)
        {
            max=1e6;
            while(max--)
            {
                for(int i=0;i<n;i++)
                {
                    arr[i]/=2;
                    if(arr[i]%2)
                    {
                        notOdd=0;
                        break;
                    }
                }
                ans+=notOdd;
                if(!notOdd)
                    break;


            }


        }
        cout << ans << endl;

    }

   return 0;

}