
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
vector<long int> li;

void primeFactorization(long int n,long int N)
{
    long int a = 2;
    //vector<long int> res;
    //int pre = a;
    int cnt=0;

    while (n >= a * a) {
        if (n % a == 0) {
            //res.push_back(a);//cout << a << " * ";
            n /= a;
            cnt++;
            if((cnt%N)==0)li.push_back(a);
        } else {
            a++;
            cnt=0;
        }
    }
    //res.push_back(n);//cout << n<<endl;
    if((cnt%N)==(N-1)&&n==a)li.push_back(a);
    //return res;    
}

int main()
{
    long int N,P;
    
    cin >> N >> P;
    
    long int r=1;
    
    if(N==1)r=P;
    else{
        primeFactorization(P,N);
 
        for(int x : li){
	        r*=x;
        }       
    }
    cout << r <<endl;
    
    return 0;
}
