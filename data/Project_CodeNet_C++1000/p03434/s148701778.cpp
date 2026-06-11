#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using Vec = vector<int>;

bool IsPrime(int num)
{
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false; 
    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2)
    {
        if (num % i == 0)
        {
            // 素数ではない
            return false;
        }
    }

    // 素数である
    return true;
}


int main(){

    int n;
    cin>>n;
    Vec vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }   
    sort(vec.begin(),vec.end());

    int a=0,b=0;

    for(int i=n-1;0<=i;i--){

        if(i%2==0){
            b+=vec[i];
        }
        else{
            a+=vec[i];
        }
        
    }
    cout<<abs(a-b)<<endl;


}