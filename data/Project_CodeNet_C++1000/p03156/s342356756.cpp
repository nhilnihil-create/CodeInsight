#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int main(void){
    int n;
    cin >> n;
    
    int a, b;
    cin >> a >> b;
    
    int number_of_first = 0;
    int number_of_second = 0;
    int number_of_third = 0;
    
    for (int i = 0; i < n; i++){
        int p;
        cin >> p;
        
        if (p <= a) number_of_first++;
        else if (a+1 <= p && p <= b) number_of_second++;
        else number_of_third++;
    }
    
    int temp = min(number_of_first,number_of_second);
    int ans = min(temp,number_of_third);
    cout << ans << endl;
}
