#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string u,d;
    cin>>u>>d;
    reverse(u.begin(),u.end());
    cout<<(u==d?"YES":"NO")<<endl;
}
