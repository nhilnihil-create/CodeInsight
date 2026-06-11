// be name khoda
#include<bits/stdc++.h>
 
using namespace std;
 
#define F first
#define S second
//#define mp make_pair 
typedef long long ll;
#define int long long
#pragma GCC optimize("Ofast")
 
const int maxn = 1e5+10;
const int mod = 1e9+7;
const ll inf = 1e18+10;
//const int N = 2e6+10;
 
int n, k;
int a[maxn];

signed main()
{
    // ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int N = 30000, sum = 0;
    set<int> se, m21, m22, m3, m6;
    for(int i = 1; i <= N; i++)
        if(i%3 == 0 || i%2 == 0)
        {
            if(i%6 == 0) m6.insert(i);
            if(i%3 == 0 && i%2 != 0 && i != 3) m3.insert(i);
            if(i%2 == 0 && i%3 != 0 && i != 2) 
            {
                if(i%3 == 1) m21.insert(i);
                if(i%3 == 2) m22.insert(i);
            }
            se.insert(i);
            sum += i;
        }
    //cout<< sum <<" "<< sum%6 <<"\n";
    cin>> n;

    if(n == 3)
        return cout<< 2 <<" "<< 5 <<" "<< 63, 0;
    if(n == 4)
        return cout<< 2 <<" "<< 5 <<" "<< 63 <<" "<< 20, 0;
    if(n == 5)
        return cout<< 2 <<" "<< 3 <<" "<< 9 <<" "<< 10 <<" "<< 18, 0;

    while(se.size() > n+1 && m3.size() >= 2)
    {
        auto it = m3.begin();
        int X = (*it); it++;
        int Y = (*it); 
        m3.erase(Y); 
        m3.erase(X); 
        se.erase(X);
        se.erase(Y);
    //    if((X+Y) % 6 != 0) 
  //          cout<< X <<" "<< Y <<"\n";
    }
    
    while(se.size() > n+2 && m21.size() >= 3)
    {
        auto it = m21.begin();
        int X = (*it); it++;
        int Y = (*it); it++;
        int Z = (*it); m21.erase(Z);m21.erase(Y); m21.erase(X);
        se.erase(X);
        se.erase(Y);
        se.erase(Z);
   //     if((X+Y+Z) % 6 != 0)    
   //         cout<< X <<" "<< Y <<" "<< Z <<"\n";
    }

    while(se.size() > n+2 && m22.size() >= 3)
    {
        auto it = m22.begin();
        int X = (*it); it++;
        int Y = (*it); it++;
        int Z = (*it); m22.erase(Z); m22.erase(X); m22.erase(Y);
        se.erase(X);
        se.erase(Y);
        se.erase(Z);
   //     if((X+Y+Z) % 6 != 0)    
   //         cout<< X <<" "<< Y <<" "<< Z <<"\n";
    }

    while (se.size() > n && m6.size())
    {
        int X = *m6.begin(); 
        m6.erase(X);
        se.erase(X);
    }
    
    sum = 0;
    for(auto x : se) 
    {
        cout<< x <<" ";
        sum += x;
    }
    //cout<<"\n"<< sum <<" "<< sum % 6;
}
