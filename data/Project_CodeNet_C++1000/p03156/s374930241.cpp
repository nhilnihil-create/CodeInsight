#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;cin>>n;
    int a, b;cin>>a>>b;
    vector<int> scores(n);for (int i=0;i<n;i++){cin>>scores[i];}

    int one, two, three;
    one = two = three = 0;
    for (auto s: scores){
        if (s <= a){
            one++;
        } else if (b + 1 <= s){
            three++;
        } else {
            two++;
        }
    }
    cout << min(min(one, two), three) <<endl;
    return 0;

}