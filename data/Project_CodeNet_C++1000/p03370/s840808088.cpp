#include <iostream>
#include <algorithm>
using namespace std;
int main(void){
    int n,x;
    cin>>n>>x;
    int mi,m_min;
    m_min=1e+6;
    for (int i=0;i<n;i++){
        cin>>mi;
        x-=mi;
        m_min = min(m_min,mi);
    }
    int ans = n+(x/m_min);
    cout<<ans;
    
}
