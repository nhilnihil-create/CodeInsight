#include <iostream>

using namespace std;

int num;
#define MAX_L 10
char v[MAX_L];
int l;

char a[MAX_L];
int n3, n5, n7;
int counts;
void getCounts(int i);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> num;
    while(num > 0){
        v[l++] = num % 10;
        num /= 10;
    }
    int i;
    for(i = 0; i < l / 2; ++i){
        char tmp = v[i];
        v[i] = v[l - 1 - i];
        v[l - 1 - i] = tmp;
    }
    getCounts(0);
    cout << counts << '\n';
    return 0;
}

void getCounts(int i){
    if(i < l){
        counts += n3 > 0 && n5 > 0 && n7 > 0;
    }
    else{
        if(n3 == 0 || n5 == 0 || n7 == 0){
            return;
        }
        int j;
        int tag = 0;
        for(j = 0; j < l; ++j){
            if(a[j] < v[j]){
                tag = 1;
                break;
            }
            else if(a[j] > v[j]){
                tag = -1;
                break;
            }
        }
        counts += tag >= 0;
        return;
    }
    a[i] = 3;
    ++n3;
    getCounts(i + 1);
    --n3;
    a[i] = 5;
    ++n5;
    getCounts(i + 1);
    --n5;
    a[i] = 7;
    ++n7;
    getCounts(i + 1);
    --n7;
}
