#include <bits/stdc++.h>
using namespace std;
 
int main() {
int A, B;
int count_k = 0;
cin >> A >> B;

for(int i = A; i < B+1; i++){
    int n1,n2,n3,n4,n5;

    n1 = i  % 10;
    n5 = i / 10000;

    if(n1 != n5){
        continue;
    }else{
        n4 = i / 1000 - n5 * 10;
        n2 = (i % 100) / 10;
        if(n2 == n4){
            count_k++;
        } 
    }
}
cout << count_k << endl;

}