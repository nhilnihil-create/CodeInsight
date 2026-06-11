#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <map>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n) + 1; i++)
#define all(vecto) vecto.begin(), vecto.end()
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
typedef long long ll;

void ans(bool qus)
{
    if (qus == true)
        std::cout << "Yes" << std::endl;
    else
        std::cout << "No" << std::endl;
}

void Ans(bool qust)
{
    if (qust == true)
        std::cout << "YES" << std::endl;
    else
        std::cout << "NO" << std::endl;
}

using namespace std;

/////////////////////////////////////////

int main(){
    int a,b,c;
    cin>>a>>b>>c;
    if(a==b){
        cout << c << endl;
    }
    else if(b==c){
        cout << a << endl;
    }
    else
        cout << b << endl;
}
