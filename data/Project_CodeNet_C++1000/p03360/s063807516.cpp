#include<iostream>


using namespace std;

int main(void){
    int inp[3]={0};
    int max,sum=0;
    int i,j,k;
    int rem;
    cin >> inp[0] >> inp[1] >> inp[2];
    cin >> k;

    for(j=0;j<k;j++){
        max = inp[0];
        rem = 0;
        for(i=1;i<=2;i++){
            if(max<inp[i]){
                max = inp[i];
                rem = i;
            }
        }
        inp[rem] = max * 2;
    }

    for(i=0;i<3;i++){
        sum += inp[i];
    }
    cout << sum;
    return 0;
}