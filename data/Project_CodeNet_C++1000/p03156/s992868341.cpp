#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define PI 3.1415926535897932384626433
#define mod 1000000007
 
int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }
 
int lcm(int a, int b) { return a * b / gcd(a, b); }
 
int main(){
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> p(n);
    for (int i = 0; i < n; i++){
        cin >> p[i];
    }

    sort(p.begin(), p.end());

    int one, two, three;
    one = two = three = 0;
    for (int i = 0; i < n; i++){
        if(p[i] <= a){
            one++;
        }else if (p[i] > a & p[i] <= b){
            two++;
        }else if(p[i] > b){
            three++;
        }
    }

    cout << min({one, two, three}) << endl;
    return 0;
}