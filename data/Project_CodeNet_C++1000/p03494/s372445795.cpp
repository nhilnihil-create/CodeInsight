#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int i;
    int num[n];
    int check =1;
    int counter =0;
    for (i=0;i<n;i++)
        cin >> num[i];
    while(check){
        for(i=0;i<n;i++){
            if(num[i]%2 == 1){
                check=0;
                break;
            }
            num[i] = num[i]/2;
        }
        counter++;
    }
    cout << counter-1 << endl;        
        
    }