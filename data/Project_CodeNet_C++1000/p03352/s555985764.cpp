#include<math.h>
#include <bits/stdc++.h>
#include <algorithm>
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ll long long int
#define py printf("Yes\n")
#define pn printf("No\n")
#define in cin>>
using namespace std;
int INF = 1001001001;

int main()
{
    int x;
    cin >>x;
    vector <bool> expo(x+1);
    expo[1] = 1;
    for(int b=2;b<=x;b++){
    int a = b*b;
    while(a<=x){
    expo[a] = 1;
    a *= b;
    }
    }
    for(int i=x;i>=1;i--) if(expo[i]){
        cout <<i<<endl;
        return 0;
    }
}
