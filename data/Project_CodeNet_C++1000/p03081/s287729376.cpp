#include "bits/stdc++.h"

using namespace std;

#define COUNTOF(array) (sizeof(array) / sizeof(array[0]))
#define OUT(P) cout << (P) << endl
#define OUT2(P1, P2) cout << (P1) << " " << (P2) << endl
#define PRINT_ARRAY(P) for(int i=0; i<P.size(); i++) cout << P[i] << endl;
#define PRINT_ARRAY_INLINE(P) do { for(int i=0; i<P.size(); i++) cout << P[i] << " "; cout << endl; } while(0)
#define PRINT_ARRAY_WITH_LABEL(L, P) do { cout << L << ": "; PRINT_ARRAY_INLINE(P); cout << endl; } while(0)

int sum_digits(int num);
template <class T>
vector<T> copy_vector(vector<T> vec);

int n, q;

int get_ordered_golem_position(int pos, string s, string items, string orders) {
    char code = s[pos]; 
    for(int i=0; i<items.size(); i++) {
        if(code == items[i]) {
            if(orders[i] == 'L')
                pos--;
            else
                pos++; 
            code = s[pos];
        }
    } 
    return pos;
}

int get_drop_position(int left, int right, 
                        string s, string t, string d, char direction) {
    int position = left + (right-left)/2;
    int moved_position = get_ordered_golem_position(position, s, t, d); 
    if(direction == 'L') {
        if(right-left<=1) return position;
        else if(moved_position == -1) return get_drop_position(position, right, s, t, d, direction);
        else return get_drop_position(left, position, s, t, d, direction);
    } else {
        if(right-left<=1) return position;
        else if(moved_position == n) return get_drop_position(left, position, s, t, d, direction);
        else return get_drop_position(position, right, s, t, d, direction);
    }

    return 0;
}

int main() {
    //int n, q;
    string s;
    cin >> n >> q;
    cin >> s;
    string t(q, 'a'), d(q, 'a');
    for(int i=0; i<q; i++) {
        cin >> t[i] >> d[i];
    }

    //for(int i=0; i<n; i++) {
    //    cout << i << " :" << get_ordered_golem_position(i, s, t, d) << endl;
    //}
    // 落ちないギリギリのラインを攻める
    int left_pos = get_drop_position(-1, n, s, t, d, 'L');
    int right_pos = get_drop_position(-1, n, s, t, d, 'R');
   
    //cout << "LEFT_POS: " << left_pos << endl;
    //cout << "RIGHT_POS: " << right_pos << endl;

    int ans = right_pos - left_pos;
    if(ans < 0) cout << 0 << endl;
    else cout << ans << endl;
    
    return 0;
}

/******************************/
/***** DECRARED FUNCTIONS *****/
/******************************/

// integerの各桁を足す
int sum_digits(int num) {
    int rtn = 0;
    string num_str = to_string(num);
    for(int i=0; i<num_str.size(); i++) {
        rtn += num_str[i] - '0';
    }   
    return rtn;
}

// vectorのコピー
template <class T>
vector<T> copy_vector(vector<T> vec) {
    vector<T> rtn;
    rtn.reserve(vec.size());
    copy(vec.begin(), vec.end(), back_inserter(rtn));
    return rtn;
}

