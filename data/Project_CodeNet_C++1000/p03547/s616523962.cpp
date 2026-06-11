#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
char x, y;
int main(int argc, const char * argv[]){
    cin>>x>>y;
    if(x < y)cout<<"<"<<endl;
    else if(x == y)cout<<"="<<endl;
    else cout<<">"<<endl;
    return 0;
}