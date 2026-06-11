#include <bits/stdc++.h>
using namespace std;
int main (){
    vector <int> sum;
    int a,b,entrada,aux_a,aux_b;
    cin>>entrada;
    for(int i=0; i<entrada-1;i++){
        aux_b = 0;
        aux_a = 0;
        a=i+1;
        b=entrada-a;
        while(b!=0){
            aux_b += b%10;
            b = b/10;
        }
        while(a!=0){
            aux_a += a%10;
            a = a/10;
        }
        sum.push_back(aux_a+aux_b);
    }
    sort(sum.begin(),sum.end());
    cout<<sum[0]<<endl;
    return 0;
}