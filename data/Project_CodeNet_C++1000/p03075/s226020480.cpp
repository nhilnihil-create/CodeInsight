#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
using namespace std;
int main(){
    int a,b,c,d,e,k;
    cin>>a>>b>>c>>d>>e>>k;
    int MIN = min(a,min(b,min(c,min(d,e))));
    int MAX = max(a,max(b,max(c,max(d,e))));
    MAX - MIN <= k ? cout << "Yay!" : cout << ":(";
    cout << endl;
}