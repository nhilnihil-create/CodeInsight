#include <iostream>
#include <algorithm>
using namespace std;
int main(void){
    int menu[5];
    for(int i=0;i<5;i++)cin>>menu[i];
    int arr[5] = {0,1,2,3,4};
    int ans = 100000;
    do{
        int sum = 0;
        for(int i=0;i<5;i++){
            if(i == 4){
                sum += menu[arr[i]];
            }   
            else{
                sum += ((menu[arr[i]] + 9) / 10) * 10;
            }
        }
        ans = min(ans,sum);
    }while(next_permutation(arr,arr+5));
    
    cout << ans << endl;
}
