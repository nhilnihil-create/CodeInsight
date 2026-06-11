#include<iostream>
using namespace std;
int main(){
    int64_t Lo = 2,Li = 1;
    int n;
    cin >> n;
    int64_t L = 3;
    if(n>=3){
        for(int i=3;i<=n;i++){
            Lo = Li;
            Li = L; 
            L = Li + Lo;   
        }
    }
    if(n==1){
        cout << 1 << endl;
    }else if(n==2){
        cout << 3 << endl;
    }else{
        cout << L << endl;
    }
}