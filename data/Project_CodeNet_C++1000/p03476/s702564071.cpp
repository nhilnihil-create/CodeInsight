#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int q,max=101010;
    cin >> q ;
    vector<int> a(max,1);
    a[0] = 0, a[1] = 0;
    for (int i = 2; i < max; i++){
        if(a[i]==1){
            for (int j = i * 2; j < max; j+=i)
                a[j] = 0;
        }
    }
    vector<int> b(max, 0);
    for (int i = 0; i < max; i++){
        if(i%2==1){
            if(a[i]&&a[(i+1)/2])
                b[i] = 1;
        }
    }

    vector<int> s(max, 0);
    for(int i=0; i<max; i++)
        s[i + 1] = s[i] + b[i];
    int l, r;
    for (int i = 0; i < q;i++){
        cin >> l >> r;
        cout << s[r+1] - s[l] << endl;
    }
}