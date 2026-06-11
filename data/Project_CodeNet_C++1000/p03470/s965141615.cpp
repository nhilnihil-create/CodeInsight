#include <bits/stdc++.h>
using namespace std;
#define repp(i,a,b) for(int i = (int)(a) ; i < (int)(b) ; i++)
#define repm(i,a,b) for(int i = (int)(a) ; i > (int)(b) ; i--)
#define vi vector<int>
#define vs vector<string>
#define all(x) (x).begin(),(x).end()
int main() {
    int n;
    cin>>n;
    vi d(n);
    repp(i,0,n){
        cin>>d[i];
    }
    sort(all(d), greater<int>());
    int cnt=1;
    repp(i,1,n){
        if(d[i]!=d[i-1]){
            cnt++;
        }
    }
    cout<< cnt <<endl;
}