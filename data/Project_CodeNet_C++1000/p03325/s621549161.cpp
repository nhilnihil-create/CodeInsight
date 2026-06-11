#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main(){
    long long n;
    cin >> n;

    vector<long long> odd;
    vector<long long> even;

    for(long long i = 0; i < n; i++){
        long long a;
        cin >> a;
        if(a % 2 == 0){
            even.push_back(a);
        }
        else{
            odd.push_back(a);
        }
    }

    if(odd.size() == n){
        printf("0\n");
        return 0;
    }

    long long count_max = 0;
    long long count = 0;
    for(long long i = 0; i < even.size(); i++){
        long long num = even[i];
        
        while(num % 2 == 0){
            num /= 2;
            count++;
        }
        //count_max = max(count_max, count);
    }

    cout << count << endl;
    return 0;


}