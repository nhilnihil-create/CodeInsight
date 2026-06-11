#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
using namespace std;
int main(){
    int n;
    cin >> n;
    int x;
    cin >> x;
    int pre=x;
    int count=0;
    bool h=false;
    for(int i=1;i<n;i++){
        int y;
        cin >> y;
        if(h){
            h=false;
            if(y!=pre){
                pre=y;
            }
            continue;
        }
        if(y==pre){
            count++;
            h=true;
        }else{
            pre=y;
        }
    }
    cout<<count<<endl;
}