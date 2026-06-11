#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
typedef long long ll;
double n, m;
int main(int argc, const char * argv[]){
    cin>>n>>m;
    int x = ((1900 * m) + (100 * (n - m))) * pow(2, m);
    cout<<x<<endl;
    return 0;
}
