#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(){
    int N;
    cin >> N;
    int t1=0,t2,x1=0,x2,y1=0,y2;
    int i;
    string ans="Yes";

    for(i=0; i<N; i++){
        cin >> t2 >> x2 >> y2;
        if(ans=="Yes"){
            if((t2+x2+y2)%2==0 && abs(t2-t1)>=abs(x2-x1)+abs(y2-y1)){
            x1=x2;
            t1=t2;
            y1=y2;
        }
            else ans="No";
        }
    }

    cout << ans << endl;

    return 0;
}