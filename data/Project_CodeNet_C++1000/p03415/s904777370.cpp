#include<bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define endl '\n'

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;


int main()
{
    char a[3][3];
    ll i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            cin>>a[i][j];
        }
    }
    cout<<a[0][0]<<a[1][1]<<a[2][2]<<endl;
    return 0;
}
