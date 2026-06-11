#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int q;
    cin >> q;
    double a[q], b[q];
    for(int i = 0; i < q; i++){
        cin >> a[i] >> b[i];
    }
    for(int i = 0; i < q; i++){
        double sq = sqrt(a[i]*b[i]);
        long long int sqn = sq;
        long long int r;
        if(sq - sqn == 0){
            if(a[i] == sqn){
                r = (sqn-1)*2;
                cout << r << endl;
            }
            else{
                r = (sqn-1)*2 - 1;
                cout << r << endl;
            }
        }
        else{
            long long int sqr = (a[i]*b[i])/sqn;
            if(sqn*sqr == a[i]*b[i]){
                sqr = sqr-1;
            }
            if(sqr == sqn) r = sqn*2-2;
            else r = (sqn)*2 - 1;
            cout << r << endl;
        }
    }
    return 0;
}