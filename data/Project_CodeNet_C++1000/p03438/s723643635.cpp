#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    long long int suma = 0, sumb = 0;
    for(int i = 0; i < n; i++){
        suma += a[i];
        sumb += b[i];
    }

    long long int opcount = sumb - suma;
    vector<int> diff(n);
    long long int opcount_a = opcount, opcount_b = opcount;
    for(int i = 0; i < n; i++){
        if(a[i] - b[i] >= 0){
            opcount_b -= a[i] - b[i];
        }else{
            opcount_a -= (b[i]-a[i])/2;
            if((b[i]-a[i])%2 == 1){
                opcount_b--;
                opcount_a--;
            }
        }
    }

    if(opcount_a >= 0 && opcount_b >= 0 && opcount_a*2LL == opcount_b) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}