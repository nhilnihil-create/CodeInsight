#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#define ll long long
using namespace std;
/*int ghat(int a)
{
    int x = log(a) - log(2.0);
    return x;
}*/
int count(int a)
{
    int c = 0;
    while(a%2==0 && a){
        a = a/2;
        c++;
    }
    return c;
}
int main() {
    ios_base:: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int i, x;
    vector<int> p;
    for(i=0; i<n; i++){
        cin >> x;
        p.push_back(x);
    }
    int max_pow = 0;
    for(i=0; i<n; i++){
        x = count(p[i]);
        //cout << x << endl;
        //max_pow = max(x, max_pow);
        max_pow += x;
    }
    //if(max_pow) cout << max_pow + 1 << endl;
    cout << max_pow << endl;
    return 0;
}