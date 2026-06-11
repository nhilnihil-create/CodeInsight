#include <bits/stdc++.h>
#define rep0(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<string, int, int> TU;

int main()
{
    int N;
    cin >> N;
    double res=0;
    rep0(i,N){
        double a;
        string b;
        cin >> a >>  b;
        if(b=="JPY"){
            res+=a;
        }else{
            res+=a*380000;
        }
    }
    cout << res << endl;
}
