#include <iostream>
#include <set>
using namespace std;
int main(void){
    // Your code here!
    int n;
    cin >> n;
    
    int last = -1;
    int count=0;
    for(int i=0; i<n; i++) {
        int tmp;
        cin >> tmp;
        if(tmp == last) {
            count++;
            last = -1;
        }else {
            last = tmp;
        }
    }
    cout << count << endl;
    
}
