#include <iostream>
#include <string>
using namespace std;

int sum(int x){
    int sum = 0;
    while(x>0){
        sum += x%10;
        x /= 10;
    }
    return sum;
};

int main(){
    int N;
    cin>>N;
    string s = "No";
    if(N%sum(N) == 0){
        s = "Yes";
    }
    cout<<s<<endl;
}
