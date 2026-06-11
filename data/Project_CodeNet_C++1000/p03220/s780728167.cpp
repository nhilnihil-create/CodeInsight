#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int N;
    int T,A;
    int H[N];
    cin>>N>>T>>A;
    for(int i=0;i<N;i++){
        cin >> H[i];
    }
    double dif = 10000;
    int number;
    for(int i=0;i<N;i++){
        double Ti = T - H[i] * 0.006;
        double res = abs(Ti-A);
        if(res<dif){
            dif = res;
            number = i;
        }
    }
    cout<<number+1<<endl;
}