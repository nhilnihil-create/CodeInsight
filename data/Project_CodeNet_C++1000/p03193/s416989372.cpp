#include <iostream>
using namespace std;

int main(){
    long long n,h,w;cin>>n>>h>>w;
    long long a, b;
    int acc = 0;
    for (int i=0;i<n;i++){
        cin >> a >> b;
        if (h <= a && w <= b){
            acc++;
        }
    }
    cout << acc << endl;
    return 0;

}