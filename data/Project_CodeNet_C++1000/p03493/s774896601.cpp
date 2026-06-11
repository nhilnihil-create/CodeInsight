#include <bits/stdc++.h>          
using namespace std;               

int main() {
    int data;
    cin >> data;
    int s1,s2,s3;
    s1 = data/100;
    s2 = (data-s1*100)/10;
    s3 = data-s1*100-s2*10;
    int count;
    count = s1+s2+s3;
    cout << count << endl;
}