#include<iostream>
#include<math.h>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<stdlib.h>
#include<map>
#include<stack>
using namespace std;
#define PI 3.14159265358979
typedef  long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#include<set>
int main(void)
{
    string s;
    cin>>s;
    map<char,bool> alpha;

    if(s=="zyxwvutsrqponmlkjihgfedcba")
    {
        cout<<-1<<endl;
        return 0;
    }
    rep(i,s.size())
    {
        alpha[s[i]] = true;
    }
    for (char c = 'a'; c <= 'z'; c++)
    {
        if(alpha[c]==false)
        {
            s += c;
            cout << s << endl;
            return 0;
        }
        
    }
    string o =s;
    if(next_permutation(s.begin(),s.end()))
    {
        rep(j,s.size())
        {
            if(s[j]==o[j]) cout<<s[j];

            else
            {
                cout<<s[j]<<endl;;
                
                return 0;
            }
            
        }
        cout<<s<<endl;
        return 0;

    }


    cout<<-1<<endl;
    

}