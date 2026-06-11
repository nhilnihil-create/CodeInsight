#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    int s1,s2,s3,s4;
    s1 = N /1000;
    s2 = (N - s1*1000 )/100;
    s3 = (N - s1*1000 - s2*100)/10;
    s4 = N - s1*1000 - s2*100 - s3*10;
    if (s1 == s2 && s2 == s3){
        cout << "Yes" << endl;
    
    }
    else if (s2 == s3 && s3 == s4){
        cout << "Yes" << endl;
    }
    else if (s1 == s2 && s2== s3 && s3 == s4){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}