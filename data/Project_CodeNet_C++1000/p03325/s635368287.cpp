#include<iostream>
#include<vector>
using namespace std;
int main(){
    int N;
    int kawadasan=0;
    cin>>N;
    vector<int> a(N);
    for(int i=0;i<N;i++){
        cin>>a[i];
        while(true){
            if(a[i]%2==0){
                a[i]/=2;
                kawadasan++;
            }else{
                break;
            }
        }
    }
    cout<<kawadasan;
}