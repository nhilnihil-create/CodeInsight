#include<iostream>

using namespace std;

int main(){
    int N;
    cin >> N;

    int total=0;
    int res=0;
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            total=4*j+7*i;
            if(total==N){
                ++res;
                break;
            }
        }
    }

    if(res>0){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}