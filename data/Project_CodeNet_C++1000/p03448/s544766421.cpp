#include <iostream>
#include <string>
using namespace std;

bool check(int x);

int main(void){
    // Your code here!
    int x,a,b,c,count = 0;
    cin >> a >> b >> c >> x;
    if(!check(x)){
        cout << "Error" << endl;
        return 0;
    }
    for(int i=0;i<=a;i++){
        for(int j=0;j<=b;j++){
            for(int k=0;k<=c;k++){
                if(x == (500*i+100*j+50*k)) count++;
            }
        }
    }
    cout << count << endl;
    return 0;
}

bool check(int x){
    if(x%50 == 0) return true;
    return false;
}