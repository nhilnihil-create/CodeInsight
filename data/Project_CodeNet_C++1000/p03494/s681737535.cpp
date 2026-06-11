#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int countMin = 0;
    
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        int count = 0;
        while (a%2 == 0)
        {
            count += 1;
            a /= 2; 
        }
        
        if(i == 0){
            countMin = count;
        }else{
            if(count < countMin){
                countMin = count;
            }
        }
    }
    cout << countMin << endl;
}