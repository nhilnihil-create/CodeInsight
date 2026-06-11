#include<iostream>
using namespace std;
int main(){
    int s;
    cin >> s;
    int count = 0;
    int i;
    for(i=0;i<3;i++){
        if(s&(1<<i)){
            count++;
        }
    }
    cout << count << endl;
    return 0;
}